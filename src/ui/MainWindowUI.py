# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'MainWindowUI.ui'
#
# Created: Sat Jul 27 17:30:26 2013
#      by: pyside-uic 0.2.13 running on PySide 1.1.1
#
# WARNING! All changes made in this file will be lost!

from PySide import QtCore, QtGui

class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName("MainWindow")
        MainWindow.resize(691, 540)
        self.centralwidget = QtGui.QWidget(MainWindow)
        self.centralwidget.setObjectName("centralwidget")
        self.verticalLayout_2 = QtGui.QVBoxLayout(self.centralwidget)
        self.verticalLayout_2.setObjectName("verticalLayout_2")
        self.ltMainLayout = QtGui.QVBoxLayout()
        self.ltMainLayout.setObjectName("ltMainLayout")
        self.tvTodaySale = QtGui.QTableView(self.centralwidget)
        self.tvTodaySale.setObjectName("tvTodaySale")
        self.ltMainLayout.addWidget(self.tvTodaySale)
        self.gbCurrentFilter = QtGui.QGroupBox(self.centralwidget)
        self.gbCurrentFilter.setEnabled(True)
        self.gbCurrentFilter.setObjectName("gbCurrentFilter")
        self.horizontalLayout = QtGui.QHBoxLayout(self.gbCurrentFilter)
        self.horizontalLayout.setObjectName("horizontalLayout")
        self.ltMainLayout.addWidget(self.gbCurrentFilter)
        self.tableView = QtGui.QTableView(self.centralwidget)
        self.tableView.setObjectName("tableView")
        self.ltMainLayout.addWidget(self.tableView)
        self.verticalLayout_2.addLayout(self.ltMainLayout)
        MainWindow.setCentralWidget(self.centralwidget)
        self.mbMainMenu = QtGui.QMenuBar(MainWindow)
        self.mbMainMenu.setGeometry(QtCore.QRect(0, 0, 691, 19))
        self.mbMainMenu.setObjectName("mbMainMenu")
        self.mnDatabase = QtGui.QMenu(self.mbMainMenu)
        self.mnDatabase.setObjectName("mnDatabase")
        MainWindow.setMenuBar(self.mbMainMenu)
        self.sbMainStatusBar = QtGui.QStatusBar(MainWindow)
        self.sbMainStatusBar.setObjectName("sbMainStatusBar")
        MainWindow.setStatusBar(self.sbMainStatusBar)
        self.actSales = QtGui.QAction(MainWindow)
        self.actSales.setObjectName("actSales")
        self.actClients = QtGui.QAction(MainWindow)
        self.actClients.setObjectName("actClients")
        self.mnDatabase.addAction(self.actSales)
        self.mnDatabase.addAction(self.actClients)
        self.mbMainMenu.addAction(self.mnDatabase.menuAction())

        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def retranslateUi(self, MainWindow):
        MainWindow.setWindowTitle(QtGui.QApplication.translate("MainWindow", "MainWindow", None, QtGui.QApplication.UnicodeUTF8))
        self.gbCurrentFilter.setTitle(QtGui.QApplication.translate("MainWindow", "Текущий фильтр", None, QtGui.QApplication.UnicodeUTF8))
        self.mnDatabase.setTitle(QtGui.QApplication.translate("MainWindow", "База данных", None, QtGui.QApplication.UnicodeUTF8))
        self.actSales.setText(QtGui.QApplication.translate("MainWindow", "Продажи", None, QtGui.QApplication.UnicodeUTF8))
        self.actClients.setText(QtGui.QApplication.translate("MainWindow", "Клиенты", None, QtGui.QApplication.UnicodeUTF8))

