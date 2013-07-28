#!/usr/bin/env python
# -*- coding: utf-8 -*-
from libs.configobj import ConfigObj
import os

# Класс для хранения и изменения настроек приложения
# Настройки хранятся в конфиге
class Settings:
    # Настройки по умолчанию
    def __init__(self):
    	programDir =  os.path.dirname(os.path.realpath(__file__))

    	self.configFilename = "config"
    	self.configPath = os.path.join(programDir, self.configFilename)
    	self.config = None

    	#Если существует файл - читаем из него настройки
    	if os.path.isfile(self.configFilename): self.config = ConfigObj(self.configPath)
    	else: self.config = self.createDefaultConfig()

    # Создание начального конфига
    def createDefaultConfig(self):
    	config = ConfigObj()
    	config.filename = self.configPath

    	#Основные настройки
    	config['Main'] = {}
    	config['Main']['DatabaseName'] = 'shop.db'
    	config['Main']['ViewFontSize'] = 8 
    	config['Main']['ViewCellHeight'] = 20

    	#Таблица продуктов
    	config['ProductsView'] = {}
    	config['ProductsView']['ColumnsWidth'] = (100, 100, 100, 50, 100, 50, 100, 100, 100)

    	#Записываем
    	config.write()
    	return config

    def getProductViewColumnsWidth(self):
    	return self.config['ProductsView']['ColumnsWidth']

    def getViewFontSize(self):
    	return int(self.config['Main']['ViewFontSize'])

    def getViewCellHeight(self):
    	return int(self.config['Main']['ViewCellHeight'])

    def setProductViewColumnsWidth(self, width):
    	self.config['ProductsView']['ColumnsWidth'] = width
    	self.config.write()

    def getDatabaseName(self):
    	return self.config['Main']['DatabaseName']


# Глобальная переменная для хранения настроек
settings = Settings()
