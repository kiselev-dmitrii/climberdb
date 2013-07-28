#!/usr/bin/env python
# -*- coding: utf-8 -*-
from PySide.QtGui import *
from ui.MainWindowUI import *
from ProductsView import *

class MainWindow(QMainWindow):
	def __init__(self):
		QMainWindow.__init__(self)
		self.initUI()

	def initUI(self):
		#Устанавливаем настройки UI
		self.ui = Ui_MainWindow()
		self.ui.setupUi(self)	

		#Создаем таблицу
		self.ui.tvProducts = ProductsView()
		self.ui.ltMainLayout.insertWidget(0, self.ui.tvProducts)
