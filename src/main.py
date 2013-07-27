#!/usr/bin/env python
# -*- coding: utf-8 -*-
import sys
from PySide import QtCore, QtGui
from MainWindow import *

def main():
	app = QtGui.QApplication(sys.argv)

	mainWindow = MainWindow()
	mainWindow.show()
	sys.exit(app.exec_())

if __name__ == "__main__":
	main()