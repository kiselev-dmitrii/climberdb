#!/usr/bin/env python
# -*- coding: utf-8 -*-
import sqlite3
import datetime
import os, sys
import math

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
			gender = u'Жен.'
		elif expression == 'man_shtany':
			type = u'Штаны'
			gender = u'Муж.'
		elif expression == 'rub_mab':
			type = u'Рубашка'
			gender = u'Муж.'
		elif expression == 'share_ware': 
			type = u'Шары вары'
		else:
		#Правила
			for value in expression.split("_"):
				if value[:3] == 'man': gender = u'Муж.'
				elif value[:4] in ['girl', 'gerl']: gender = u'Жен.'

				elif value in ['j', 'g']: type = u'Джинсы'
				elif value[:4] == 'batn' or value == 'batik': type = u'Батник'
				elif value[:4] in ['blyz', 'bluz', 'blaz']: type = u'Блуза'
				elif value[:4] in ['bruk', 'bryk']: type = u'Брюки'
				elif value[:5] == 'bryuk': type = u'Брюки'
				elif value == 'gilet': type = u'Жилет'
				elif value == 'jaket': type = u'Жакет'
				elif value == 'kapri': type = u'Капри'
				elif value in ['kardigan', 'kerdigan']: type = u'Кардиган'
				elif value in ['kostym', 'kostjm']: type = u'Костюм'
				elif value in ['kurtka', 'kyrtka', 'kertka', 'rurtka']: type = u'Куртка'
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
				elif value[:3] == 'rub': type = u'Рубашка'
				elif value[:6] == 'futbol': type = u'Футболка'
				elif value[:4] in ['pidg', 'pidj', 'pidz']: type = u'Пиджак'
				elif value[:5] in ['tunik', 'tynik']: type = u'Туника'
				elif value == 'plash': type = u'Плащ'
				elif value == 'polo': type = u'Поло'
				elif value == 'poluver': type = u'Полувер'
				elif value == 'sarafan': type = u'Сарафан'
				elif value == 'sharf': type = u'Шарф'
				elif value[:8] == 'tolstovk': type = u'Толстовка'
				elif value == 'topik': type = u'Топик'


				elif value == 'utep': coment = u'Утепленные'
				elif value == 'len': comment = u"Лён"
				elif value == 'kopeshonom': comment = u"С капюшоном"

		return (type, gender, comment)

class Converter:
	def __init__(self, oldDirectory, pathToDb):
		self.oldDir = oldDirectory
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

	def _getTypeIdByName(self, name):
		query = "SELECT Id FROM Type WHERE Name = ?"
		self.db.cursor.execute(query, [name])
		typeID = self.db.cursor.fetchall()[0][0]
		return typeID

	def _insertItems(self, items):
		db = self.db

		for item in items:
			#Получаем typeID по его имени
			typeID = None
			if item.type: typeID = self._getTypeIdByName(item.type)
			#print typeID

			#Вставляем item в Consignment
			query = """
						INSERT INTO Consignment (Name, Model, TypeID, Gender, Comment, Cost) 
						VALUES (?, ?, ?, ?, ?, ?)
					"""	
			db.cursor.execute(query, [item.name, item.model, typeID, item.gender, item.comment, item.cost])

			#Получаем ID вставленной записи
			ConsignmentID = db.cursor.lastrowid
			#print ConsignmentID

			#Генерируем штрихкоды по номеру партии и размерам
			barcodes = self._generateBarcodes(ConsignmentID, item.sizes)

			for size in item.sizes:
				#Вставляем размеры в Products
				query = "INSERT INTO Product (ConsignmentID, Size, Barcode, IsSold, DeliveryDate) VALUES (?, ?, ?, ?, ?)"
				db.cursor.execute(query, [ConsignmentID, size, barcodes[size], False, item.date])

	def convertBaseDB(self):
		items = self._loadItemsFromFile(os.path.join(self.oldDir, "base.dat"))
		self._insertTypesToDB(items)
		self._insertItems(items)
		self.db.connection.commit()

	def _insertSoldItems(self, items, saleDate):
		db = self.db

		for item in items:
			#Ищем ConsignmentID по имени и модели
			ConsignmentID = None

			query = "SELECT ID FROM Consignment WHERE Name = ? AND Model = ? AND Cost = ?"
			db.cursor.execute(query, [item.name, item.model, item.cost])
			rows = db.cursor.fetchall()
			if len(rows) > 0:
				ConsignmentID = rows[0][0]
			else: 
				#Иначе, нужно добавить новую запись
				#Получаем typeID по его имени
				typeID = None
				if item.type: typeID = self._getTypeIdByName(item.type)

				query = """
						INSERT INTO Consignment (Name, Model, TypeID, Gender, Comment, Cost) 
						VALUES (?, ?, ?, ?, ?, ?)
					"""	
				db.cursor.execute(query, [item.name, item.model, typeID, item.gender, item.comment, item.cost])
				ConsignmentID = db.cursor.lastrowid

			#Генерируем штрихкоды по номеру партии и размерам
			barcodes = self._generateBarcodes(ConsignmentID, item.sizes)

			#Вставляем размеры
			for size in item.sizes:
				#Вставляем размеры в Products
				query = "INSERT INTO Product (ConsignmentID, Size, Barcode, IsSold, SellingCost, DeliveryDate, SaleDate) VALUES (?, ?, ?, ?, ?, ?, ?)"
				db.cursor.execute(query, [ConsignmentID, size, barcodes[size], True, item.cost, item.date, saleDate])

	def convertSaleDB(self):
		tree = os.walk(os.path.join(self.oldDir, "sales"))
		for d in tree:
			if d[2] == ["today.dat"]:
				filename = d[2][0]
				path = d[0]
				date = '.'.join(path.split('/')[-3:])
				saleDate = datetime.datetime.strptime(date, "%Y.%m.%d") 

				items = self._loadItemsFromFile(os.path.join(path, filename))
				self._insertSoldItems(items, saleDate)

		self.db.connection.commit()

	def _generateBarcodes(self, consignmentID, sizes):
		# size -> barcode
		barcodes = {}

		i = 0
		for size in sizes:
			if not barcodes.has_key(size): 
				firstPart = '{:0>6}'.format(consignmentID)
				secondPart = '{:0>6}'.format(i)
				checkDigit = self._generateCheckDigit(firstPart + secondPart)
				barcodes[size] = firstPart + secondPart + str(checkDigit)
				i += 1

		return barcodes

	def _generateCheckDigit(self, barcode12):
		reverse = barcode12[::-1]

		sumOdd = 0
		for digit in reverse[0::2]: sumOdd += int(digit)
		sumEven = 0
		for digit in reverse[1::2]: sumEven += int(digit)

		result = 3*sumOdd + sumEven;
		result = int(math.ceil(float(result)/10)*10) - result
		return result

def main():
	converter = Converter(sys.argv[1], sys.argv[2])
	converter.convertBaseDB()
	converter.convertSaleDB()

if __name__ == "__main__":
	main()



