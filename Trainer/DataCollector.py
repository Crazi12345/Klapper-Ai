from logging import root
from operator import imod
import psycopg2 as pgres
import pyaudio as pa
import wave
import numpy as np
import matplotlib.pyplot as plt
from tkinter import *
from tkinter import ttk

chunk = 100
sample_format = pa.paInt16
channels = 1
sps = 1000
seconds = 0.5
filename = "output.wav"
path = "output.wav"
p = pa.PyAudio()

# shows the sound waves
def visualize():
   
    # reading the audio file
    raw = wave.open(path)
     
    # reads all the frames
    # -1 indicates all or max frames
    signal = raw.readframes(-1)
   
    signal = np.frombuffer(signal, dtype ="int16")
    print(signal)
    print(len(signal))
    # gets the frame rate
    f_rate = raw.getframerate()
 
    # to Plot the x-axis in seconds
    # you need get the frame rate
    # and divide by size of your signal
    # to create a Time Vector
    # spaced linearly with the size
    # of the audio file
    time = np.linspace(
        0, # start
        len(signal) / f_rate,
        num = len(signal)
    )
 
    # using matplotlib to plot
    # creates a new figure
    plt.figure(1)
     
    # title of the plot
    plt.title("Sound Wave")
     
    # label of x-axis
    plt.xlabel("Time")
    
    # actual plotting
    plt.plot(time, signal)
     
    # shows the plot
    # in new window
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


def saveToWav(frames):

    # Save the recorded data as a WAV file
    wf = wave.open(filename, 'wb')
    wf.setnchannels(channels)
    wf.setsampwidth(p.get_sample_size(sample_format))
    wf.setframerate(sps)
    wf.writeframes(b''.join(frames))
    wf.close()

connection = pgres.connect( user = "postgres",
                            host = "192.168.0.104",
                            port = "5432",
                            database = "isaac")



print(pa.get_portaudio_version())

root = Tk()
frm = ttk.Frame(root,padding=10)
frm.grid()

ttk.Label(frm, text="Hello World!").grid(column=0, row=0)
b1 = Button(frm, text="record", command=record).grid(column=1, row=0)
b2 =Button(frm, text="visualize", command=visualize).grid(column=2, row=0)
root.mainloop()

print("Connected successfully to PostgreSQL")