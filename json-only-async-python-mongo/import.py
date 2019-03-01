import csv
from pymongo import MongoClient

csvfile = open('data.csv', 'r')
reader = csv.DictReader( csvfile )
headers = reader.fieldnames

client = MongoClient()
countries = client.db.countries 
countries.drop()

for row in reader:
    doc={}
    for field in headers:
        doc[field]=row[field]
    countries.insert(row)
    print(doc)