import argparse
import os

parser = argparse.ArgumentParser()
group = parser.add_mutually_exclusive_group()
group.add_argument("-p", "--pad", action = "store_true")
group.add_argument("-d", "--delete", action = "store_true")
args = parser.parse_args()

dir_name = os.path.dirname(os.path.realpath(__file__))

if args.pad:
    blank_space_index = min(file_name.index(" ") for file_name in os.listdir(dir_name) if file_name.startswith("#"))
    for file_name in os.listdir(dir_name):
        if file_name.startswith("#") and file_name.index(" ") == blank_space_index:
            new_name = "#0" + file_name[1:]
            os.rename(file_name, new_name)
elif args.delete:
    for file_name in os.listdir(dir_name):
        if file_name.startswith("#0"):
            new_name = "#" + file_name[2:]
            os.rename(file_name, new_name)
