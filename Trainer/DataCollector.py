from logging import root
from operator import imod
from signal import signal
import psycopg2 as pgres
import pyaudio as pa
import wave
import numpy as np
import matplotlib.pyplot as plt
from tkinter import *
from tkinter import ttk

from setuptools import Command
selectedRadio = 0
chunk = 100
sample_format = pa.paInt16
channels = 1
sps = 1000
seconds = 0.5
filename = "output.wav"
path = "output.wav"
p = pa.PyAudio()
signalArray = [1]
#selectedRadio = 0

# shows the sound waves

def makeSignal():
    raw = wave.open(path)

    # -1 indicates all or max frames
    signal = raw.readframes(-1)
   
    signal = np.frombuffer(signal, dtype ="int16")
    return signal

def visualize():
   
    # reading the audio file
    raw = wave.open(path)

    # -1 indicates all or max frames
    signal = raw.readframes(-1)
   
    signal = np.frombuffer(signal, dtype ="int16")
    print(signal)
   
    f_rate = raw.getframerate()

    time = np.linspace(
        0, # start
        len(signal) / f_rate,
        num = len(signal)
    )
 
    signalArray = signal
    plt.figure(1)
    plt.title("Sound Wave")
    plt.xlabel("Time")
    plt.plot(time, signal)
    print(signalArray)
    plt.show()
 
def record():
   
    p = pa.PyAudio()
  
    print("recording")

    stream = p.open(format=sample_format,
                    channels=channels,
                    rate = sps,
                    frames_per_buffer=chunk,
                    input=True)

    frames = []  # Initialize array to store frames

    # Store data in chunks for 3 seconds
    for i in range(0, int(sps / chunk * seconds)):
        data = stream.read(chunk)
        frames.append(data)

    # Stop and close the stream 
    stream.stop_stream()
    stream.close()
    # Terminate the PortAudio interface
    p.terminate()
    print('Finished recording')
    saveToWav(frames)

def insert():
   
    conn = connect()
    raw = wave.open(path)

    # -1 indicates all or max frames
    signalA = raw.readframes(-1)
   
    signaA = np.frombuffer(signalA, dtype ="int16")
    cur  = conn.cursor()
    if selectedRadio.get() == 1:
        j = "Clab"
    else:
        j = "No Clab"
 
    
    i = makeSignal().tolist()
   
    cur.execute(
        "insert into untraineddata(data,label) values (%s,%s)",
        (i, j))
    conn.commit()
    cur.close()
    
def printI():
    
    print(selectedRadio.get())

def saveToWav(frames):

    # Save the recorded data as a WAV file
    wf = wave.open(filename, 'wb')
    wf.setnchannels(channels)
    wf.setsampwidth(p.get_sample_size(sample_format))
    wf.setframerate(sps)
    wf.writeframes(b''.join(frames))
    wf.close()


def connect():
    connection = pgres.connect( user = "postgres",
                                host = "192.168.0.104",
                                port = "5432",
                                database = "isaac")
    return connection



print(pa.get_portaudio_version())

root = Tk()
frm = ttk.Frame(root,padding=10)
frm.grid()

selectedRadio = IntVar()
ttk.Radiobutton(root, 
               text="Clap",
               variable=selectedRadio,
             
               value=1).grid(column=0,row=2)

ttk.Radiobutton(root, 
               text="Not a Clab",
               
               value=2,variable=selectedRadio,
               command = selectedRadio
               ).grid(column=1,row=2)

ttk.Label(frm, text="Trainer").grid(column=0, row=0)
b1 = Button(frm, text="record", command=record).grid(column=1, row=0)
b2 =Button(frm, text="visualize", command=visualize).grid(column=2, row=0)
b3 =Button(frm, text="send to database",command=insert).grid(column=3, row=2)
root.mainloop()

print("Connected successfully to PostgreSQL")