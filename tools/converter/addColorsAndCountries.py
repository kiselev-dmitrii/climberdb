#!/usr/bin/env python
# -*- coding: utf-8 -*-
import sqlite3
import sys

def main():
	connection = sqlite3.connect(sys.argv[1])	
	cursor = connection.cursor()

	colors = [	
				u"Черный", 
				u"Коричневый",
				u"Синий",
				u"Темносиний",
				u"Красный",
				u"Зеленый",
				u"Голубой",
				u"Желтый"
			 ]

	countries = [ u"Турция", u"Китай", u"ОАЭ", u"Индонезия", u"Сирия"]

	colors = map(lambda x: (x,), colors)
	countries = map(lambda x: (x,), countries)

	query = "INSERT INTO Color (Name) VALUES (?)"
	cursor.executemany(query, colors);
	
	query = "INSERT INTO Country (Name) VALUES (?)"
	cursor.executemany(query, countries);

	connection.commit()

if __name__ == "__main__":
	main()