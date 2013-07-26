#!/usr/bin/env python
# -*- coding: utf-8 -*-
import sqlite3
import datetime
import os, sys

class Database:
	def __init__(self, path):
		self.connection = sqlite3.connect(path)
		self.cursor = self.connection.cursor()

class Item:
	def __init__(self, name, model, sizes, cost, date, type):
		self.name = name.replace("_", " ")
		self.model = model.replace("_", " ")
		self.sizes = sizes.split(",")

		try: self.cost = int(cost)
		except ValueError: self.cost = None

		self.date = datetime.datetime.strptime(date, "%d.%m.%Y_%H:%M")
		self.type, self.gender, self.comment = self._convertType(type)

	def _convertType(self, expression):
		type = None
		gender = None
		comment = None 
		self.expression = expression

		#Эвристики
		if expression == 'jgirl': 
			type = u'Джинсы'
			gender = u'Female'
		elif expression == 'man_shtany':
			type = u'Штаны'
			gender = u'Male'
		elif expression == 'rub_mab':
			type = u'Рубашка'
			gender = u'Male'
		elif expression == 'share_ware': 
			type = u'Шары вары'
		else:
		#Правила
			for value in expression.split("_"):
				if value[:3] == 'man': gender = u'Male'
				elif value[:4] in ['girl', 'gerl']: gender = u'Female'

				elif value in ['j', 'g']: type = u'Джинсы'
				elif value[:4] == 'batn': type = u'Батник'
				elif value[:4] in ['blyz', 'bluz']: type = u'Батник'
				elif value[:4] in ['bruk', 'bryk']: type = u'Брюки'
				elif value[:5] == 'bryuk': type = u'Брюки'
				elif value == 'gilet': type = u'Жилет'
				elif value == 'jaket': type = u'Жакет'
				elif value == 'kapri': type = u'Капри'
				elif value in ['kardigan', 'kerdigan']: type = u'Кардиган'
				elif value == 'kostym': type = u'Костюм'
				elif value in ['kurtka', 'kyrtka']: type = u'Куртка'
				elif value == 'legensy': type = u'Легенсы'
				elif value == 'losiny': type = u'Лосины'
				elif value[:4] == 'maik': type = u'Майка'
				elif value[:5] == 'olimp': type = u'Олимпика'
				elif value[:4] == 'jubk': type = u'Юбка'
				elif value[:4] == 'plat': type = u'Платье'
				elif value[:3] == 'rub': type = u'Рубашка'
				elif value[:5] in ['short', 'shert', 'shery', 'schor', 'serty'] : type = u'Шорты'
				elif value[:3] == 'rem': type = u'Ремень'
				elif value[:5] == 'kofta': type = u'Кофта'
				elif value[:7] == 'vodolaz': type = u'Водолазка'
				elif value[:4] in 'svit': type = u'Свитер'
				elif value[:5] in 'sivit': type = u'Свитер'
				elif value[:5] == 'shtan': type = u'Штаны'
				elif value[:5] == 'triko': type = u'Трико'
				elif value[:5] == 'sumka': type = u'Сумка'
				elif value[:6] == 'futbol': type = u'Футболка'
				elif value[:4] in ['pidg', 'pidj']: type = u'Пиджак'
				elif value[:5] in ['tunik', 'tynik']: type = u'Туника'
				elif value == 'plash': type = u'Плащ'
				elif value == 'polo': type = u'Поло'
				elif value == 'poluver': type = u'Полувер'
				elif value == 'sarafan': type = u'Сарафан'
				elif value == 'sharf': type = u'Шарф'
				elif value == 'tolstovka': type = u'Толстовка'
				elif value == 'topik': type = u'Топик'


				elif value == 'utep': coment = u'Утепленные'
				elif value == 'len': comment = u"Лён"
				elif value == 'kopeshonom': comment = u"С капюшоном"

		return (type, gender, comment)

class Converter:
	def __init__(self, pathToDb):
		self.db = Database(pathToDb)

	def _loadItemsFromFile(self, filePath):
		f = file(filePath)

		items = []
		for line in f:
			record = line.split("\t")
			item = Item(record[0], record[1], record[2], record[3], record[4], record[5])
			items.append(item)
		return items

	def _insertTypesToDB(self, items):
		types = set()
		for item in items: types.add((item.type,))
		types.remove((None,))

		query = "INSERT INTO Type (Name) VALUES (?)"
		self.db.cursor.executemany(query, list(types))

	def _insertItems(self, items):
		db = self.db

		for item in items:
			#Получаем typeID по его имени
			typeID = None
			if item.type:
				query = "SELECT Id FROM Type WHERE Name = ?"
				db.cursor.execute(query, [item.type])
				typeID = db.cursor.fetchall()[0][0]
			print typeID

			#Вставляем item в Consignment
			query = """
						INSERT INTO Consignment (Name, Model, TypeID, Gender, Comment, Cost) 
						VALUES (?, ?, ?, ?, ?, ?)
					"""	
			db.cursor.execute(query, [item.name, item.model, typeID, item.gender, item.comment, item.cost])

			#Получаем ID вставленной записи
			query = "SELECT last_insert_rowid()"
			db.cursor.execute(query)
			ConsignmentID = db.cursor.fetchall()[0][0]
			print ConsignmentID

			for size in item.sizes:
				#Вставляем размеры в Products
				query = "INSERT INTO Product (ConsignmentID, Size, IsSold, DeliveryDate) VALUES (?, ?, ?, ?)"
				db.cursor.execute(query, [ConsignmentID, size, False, item.date])

	def convertBaseDB(self, pathToTxtFile):
		items = self._loadItemsFromFile(pathToTxtFile)
		self._insertTypesToDB(items)
		self._insertItems(items)
		self.db.connection.commit()


def main():
	oldDbDir = sys.argv[1]
	pathToDb = sys.argv[2]

	converter = Converter(pathToDb)
	converter.convertBaseDB(os.path.join(oldDbDir, 'base.dat'))

if __name__ == "__main__":
	main()



