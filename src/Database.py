#!/usr/bin/env python
# -*- coding: utf-8 -*-
from PySide.QtSql import *
from Settings import *

# Класс для обращения к БД
class Database:
	def __init__(self):
		self.dbName = settings.getDatabaseName()
		self.dbPath = os.path.join(os.path.dirname(os.path.realpath(__file__)), self.dbName)
		self.createConnection(self.dbPath)

	def createConnection(self, path):
		self.db = QSqlDatabase.addDatabase('QSQLITE')
		self.db.setDatabaseName(path)
		if not self.db.open(): raise Exception("Cannot open DB")

	def getProductsViewModel(self):
		query = u"""
					SELECT 
					        C.Name as 'Наименование', 
					        C.Model as 'Модель', 
					        GROUP_CONCAT(Size, ", ") as 'Размеры',
					        C.Cost as 'Цена', 
					        Type.Name as 'Тип', 
					        C.Gender as 'Пол', 
					        C.Comment as 'Комментарии',
					        Color.Name as 'Цвет', 
					        Country.Name as 'Производитель'
					FROM  
						Consignment as C 
						JOIN 		Product as P 	ON     C.ID = P.ConsignmentID 
						LEFT JOIN 	Type      		ON     C.TypeID = Type.ID
					    LEFT JOIN 	Color 			ON     C.ColorID = Color.ID
					   	LEFT JOIN 	Country 		ON     C.CountryID = Country.ID 
					WHERE 
						P.IsSold = 0
					GROUP BY 
						C.Name, C.Model, C.Cost, C.TypeID, C.Gender, C.Comment 
					ORDER BY 
						C.ID 
				"""
		model = QSqlQueryModel()
		model.setQuery(query)

		return model


# Глобальная переменная для обращения к БД
database = Database()