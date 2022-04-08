import psycopg2 as pgres

connection = pgres.connect( user = "postgres",
                            host = "192.168.0.104",
                            port = "5432",
                            database = "isaac")

cursor = connection.cursor



print("Connected successfully to PostgreSQL")