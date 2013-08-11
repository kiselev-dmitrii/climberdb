 rm shop.db 
 sqlite3.exe shop.db < create_db.sql 
 ./converter.py old_db/ shop.db
 ./addColorsAndCountries.py shop.db
