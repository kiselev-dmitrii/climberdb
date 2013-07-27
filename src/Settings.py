#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Синглтон, для хранения и изменения настроек приложения
class Singleton(object):
    def __new__(cls):
        if not hasattr(cls, 'instance'):
             cls.instance = super(Singleton, cls).__new__(cls)
        return cls.instance

    # Настройки по умолчанию
    def __init__(self):
    	pass	

