#!/usr/bin/env python
# -*- coding: utf-8 -*-

from PySide.QtGui import *
from Settings import *
from Database import *

class ProductsView(QTableView):
	def __init__(self, parent = None):
		QTableView.__init__(self, parent)

		self.populateView()
		self.initUI()

		self.doubleClicked.connect(sayHello)

	def initUI(self):
		self.initHeaderSettings()
		self.initFontSettins()
		self.initCellSettings()

	def initCellSettings(self):
		self.setSelectionBehavior(QAbstractItemView.SelectRows)
		self.verticalHeader().setDefaultSectionSize(settings.getViewCellHeight())

	def initHeaderSettings(self):
		header = self.horizontalHeader()

		#Разворачиваем таблицу по ширине на всю
		header.setStretchLastSection(True);

		# Устанавливаем ширину колонок
		columnsWidth = settings.getProductViewColumnsWidth() 
		for i, value in enumerate(columnsWidth):
			value = int(value)
			if value == 0: header.hideSection(i)
			else: header.resizeSection(i, value)

	def initFontSettins(self):
		font = QFont()
		font.setPointSize(settings.getViewFontSize())
		self.setFont(font)

	def populateView(self):
		self.setModel(database.getProductsViewModel())

	def closeEvent(self):
		# Сохраняем ширины колонок
		width = []
		for i in xrange(0,9): width.append(self.horizontalHeader().sectionSize(i))
		settings.setProductViewColumnsWidth(width)

def sayHello(index):
	print index.row(), index.column()