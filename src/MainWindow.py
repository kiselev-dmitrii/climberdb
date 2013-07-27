#!/usr/bin/env python
# -*- coding: utf-8 -*-
from PySide.QtGui import *
from ui.MainWindowUI import *

class MainWindow(QMainWindow):
	def __init__(self):
		QMainWindow.__init__(self)

		#Создаем и устанавливаем UI на данное окно
		self.ui = Ui_MainWindow()
		self.ui.setupUi(self)	

