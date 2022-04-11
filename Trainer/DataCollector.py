import psycopg2 as pgres
import pyaudio as pa

connection = pgres.connect( user = "postgres",
                            host = "192.168.0.104",
                            port = "5432",
                            database = "isaac")



print(pa.get_portaudio_version())

print("Connected successfully to PostgreSQL")