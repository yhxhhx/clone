/*
 Copyright Zero One Star. All rights reserved.
 
 @Author: awei
 @Date: 2022/10/24 15:38:30
 
 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at
 
      https://www.apache.org/licenses/LICENSE-2.0
 
 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#ifdef USE_XLNT

#include "pch.h"
#include "../include/ExcelComponent.h"
#include "../include/CommonMacros.h"
#include <iostream>
#include "CharsetConvertHepler.h"

void ExcelComponent::createSheet(const std::string& sheetname)
{
	// �������sheet��ôɾ��sheet
	if (wb.contains(sheetname))
	{
		sheet = wb.sheet_by_title(sheetname);
		wb.remove_sheet(sheet);
	}
	// ����sheet
	sheet = wb.create_sheet();
	sheet.title(sheetname);
}

void ExcelComponent::writeLineByLine(const std::vector<std::vector<std::string>>& source)
{
	int row = 1;
	int col = 1;
	for (auto aSignRow : source)
	{
		col = 1;
		for (auto cellVal : aSignRow)
		{
			//���õ�Ԫ��ֵ
			sheet.cell(xlnt::cell_reference(col, row)).value(cellVal);
			//�����п��
			sheet.column_properties(col).custom_width = true;
			sheet.column_properties(col).width = colWidth;
			col++;
		}
		//�����и߶�
		sheet.row_properties(row).custom_height = true;
		sheet.row_properties(row).height = rowHeight;
		row++;
	}
}

void ExcelComponent::readLineByLine(xlnt::worksheet* source, std::vector<std::vector<std::string>>* target)
{
	for (auto row : source->rows(false))
	{
		std::vector<std::string> aSingleRow;
		for (auto cell : row)
		{
			aSingleRow.push_back(cell.to_string());
		}
		target->push_back(aSingleRow);
	}
}

ExcelComponent::ExcelComponent()
{
	// ��ʼ��������
	clearWorkbook();
}

void ExcelComponent::setRowHeight(double rowHeight)
{
	this->rowHeight = rowHeight;
}

void ExcelComponent::setColWidth(double colWidth)
{
	this->colWidth = colWidth;
}

void ExcelComponent::clearWorkbook()
{
	this->wb = wb.empty();
	// ɾ��Ĭ�Ϲ�����
	if (wb.contains("Sheet1"))
	{
		wb.remove_sheet(wb.active_sheet());
	}
}

void ExcelComponent::loadFile(const std::string& filename)
{
	this->wb.load(filename);
}

void ExcelComponent::writeVectorToFile(const std::string& filename, const std::string& sheetname, const std::vector<std::vector<std::string>>& data)
{
	// ����ҳǩ
	createSheet(sheetname);
	
	// ����д������
	writeLineByLine(data);

	//�ж�Ŀ¼�Ƿ���ڣ������ڴ���Ŀ¼
	auto dir = filename.substr(0, filename.find_last_of("/") + 1);
	const size_t dirLen = dir.length();
	if (dirLen > MAX_DIR_LEN)
	{
		std::cout << "ExcelComponent 120: excel save fail(file path too long)" << std::endl;
		return;
	}
	char tmpDirPath[MAX_DIR_LEN] = { 0 };
	for (size_t i = 0; i < dirLen; i++)
	{
		tmpDirPath[i] = dir[i];
		if (tmpDirPath[i] == '/')
		{
			if (ACCESS(tmpDirPath, 0) != 0)
			{
				if (MKDIR(tmpDirPath) != 0)
				{
					std::cout << "ExcelComponent 133: excel save fail(create dir " << tmpDirPath << " fail)" << std::endl;
					return;
				}
			}
		}
	}

	//���浽�ļ�
	wb.save(filename);
}

std::vector<std::uint8_t> ExcelComponent::writeVectorToBuff(const std::string& sheetname, const std::vector<std::vector<std::string>>& data)
{
	// ����ҳǩ
	createSheet(sheetname);

	// ����д������
	writeLineByLine(data);

	// ���浽������
	std::vector<std::uint8_t> buff;
	wb.save(buff);

	// ���ػ����ṩ��������ʹ��
	return buff;
}

std::vector<std::vector<std::string>> ExcelComponent::readIntoVector(const std::string& filename, const std::string& sheetname)
{
	// ����һ�����ؽ���Ķ�ά��
	std::vector<std::vector<std::string>> result;

	// ����һ����ʱ�Ĺ������������ļ�
	auto tmpWb = xlnt::workbook();
	try
	{
		tmpWb.load(filename);
	}
	catch (xlnt::exception e)
	{
		std::cout << "ExcelComponent 173: load excel fail(" << e.what() << ")" << std::endl;
		return result;
	}
	
	// �ж��Ƿ����ָ��ҳǩ
	if (!tmpWb.contains(sheetname))
	{
		std::cout << "ExcelComponent 180: read sheet fail(" << CharsetConvertHepler::utf8ToAnsi(sheetname) << " is not contain)" << std::endl;
		return result;
	}
	
	// ���ж�ȡ����
	auto sheet = tmpWb.sheet_by_title(sheetname);
	readLineByLine(&sheet, &result);

	// ���ض�ȡ���
	return result;
}

std::vector<std::vector<std::string>> ExcelComponent::readIntoVector(const char* data, size_t size, const std::string& sheetname)
{
	// ����һ�����ؽ���Ķ�ά��
	std::vector<std::vector<std::string>> result;

	// ����һ����ʱ�Ĺ������������ļ�
	auto tmpWb = xlnt::workbook();
	try
	{
		std::stringstream ss;
		ss.write(data, size);
		tmpWb.load(ss);
	}
	catch (xlnt::exception e)
	{
		std::cout << "ExcelComponent 207: load excel fail(" << e.what() << ")" << std::endl;
		return result;
	}

	// �ж��Ƿ����ָ��ҳǩ
	if (!tmpWb.contains(sheetname))
	{
		std::cout << "ExcelComponent 214: read sheet fail(" << CharsetConvertHepler::utf8ToAnsi(sheetname) << " is not contain)" << std::endl;
		return result;
	}

	// ���ж�ȡ����
	auto sheet = tmpWb.sheet_by_title(sheetname);
	readLineByLine(&sheet, &result);

	// ���ض�ȡ���
	return result;
}

#endif // USE_XLNT