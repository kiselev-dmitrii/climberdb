#!/usr/bin/env python
# -*- coding: utf-8 -*-
from PySide.QtGui import *
from PySide.QtSql import *
from ui.MainWindowUI import *

class MainWindow(QMainWindow):
	def __init__(self):
		QMainWindow.__init__(self)

		self.ui = None
		self.db = None

		self.applyUI()
		self.createConnection("shop.db")
		self.populateProductsTableView()

	def applyUI(self):
		self.ui = Ui_MainWindow()
		self.ui.setupUi(self)	

	def createConnection(self, path):
		self.db = QSqlDatabase.addDatabase('QSQLITE')
		self.db.setDatabaseName(path)
		if not self.db.open(): return False
		else: return True

	def populateProductsTableView(self):
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
		self.ui.tvProducts.setModel(model)
		self.ui.tvProducts.horizontalHeader().setStretchLastSection(True);
		self.ui.tvProducts.horizontalHeader().resizeSection(3, 50)
		self.ui.tvProducts.horizontalHeader().resizeSection(5, 50)



