import re
import os
import decimal
import xlsxwriter

def lot_ID_getter(filename):
    ID = filename.split('~')
    lot_ID = ID[0] + '-' + ID[1]
    return lot_ID

def find_raw_data_file():
    print('Looking for raw data...')

    directory = os.path.dirname(os.path.abspath(__file__))
    for filename in os.listdir(directory):
        if re.match('^[\w\.]+~\d+~([\w_]+)~[\d_-]+~(HC)\.txt$', filename):
            lot_ID = lot_ID_getter(filename)
            if f'{lot_ID}_output.xlsx' in os.listdir(directory):
                os.remove(filename)
                continue
            else:
                print(f'{lot_ID}\'s raw data found!')
                return (lot_ID, filename)
    print('Every raw data file has been converted into excel file!')
    os.system('pause')
    exit(0)

def find_useful_info(filename):
    print('Extracting distortion data...')

    cooked_data = []
    with open(filename, 'r') as file:
        for line in file.readlines():
            if re.match('^DefectID', line):
                title = [line.split(' ')[0], line.split(' ')[-1].strip()]
                cooked_data.append(title)
            elif re.match('^[\d\s-]+PO_CENTER_OFFSET\s.+', line):
                data = [line.split(' ')[0], decimal.Decimal(line.split(' ')[-1].strip())]
                cooked_data.append(data)

    print('Extraction done!')
    return tuple(cooked_data)

def output_excel(lot_ID, cooked_data):
    print('Converting into excel file...')

    workbook = xlsxwriter.Workbook(f'{lot_ID}_output.xlsx')
    worksheet_all = workbook.add_worksheet('all')
    worksheet_ng = workbook.add_worksheet('NG')
    row_all, row_ng = 0, 0
    for id, distortion in cooked_data:
        worksheet_all.write(row_all, 0, id)
        worksheet_all.write(row_all, 1, distortion)
        row_all += 1
        if row_ng == 0:
            worksheet_ng.write(row_ng, 0, id)
            worksheet_ng.write(row_ng, 1, distortion)
            row_ng += 1
        else:
            if float(distortion) >= 1.8:
                worksheet_ng.write(row_ng, 0, id)
                worksheet_ng.write(row_ng, 1, distortion)
                row_ng += 1

    print('Conversion done!')
    workbook.close()

def convert_one_raw_data():
    lot_ID, filename = find_raw_data_file()
    cooked_data = find_useful_info(filename)
    output_excel(lot_ID, cooked_data)

while True:
    convert_one_raw_data()
