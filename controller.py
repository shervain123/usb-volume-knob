'''

if you modified this code and publish it on the internet somewhere, please left these in and put your username as "editor"

original code is written by:
    greentea(youtube https://www.youtube.com/channel/UCTnM3fNV56z9NxU_HqNDCzA)
    gndatabase(twitter https://twitter.com/gndbupdates)
    shervain123(github https://github.com/shervain123)

original code can be found at:
    https://github.com/shervain123/usb-volume-knob

yes i have diffrent username depending on where you search

This simple program was made using sample code that can be found online
the sample code i used are:
    auto arduino port finder (https://stackoverflow.com/a/25112066)
    pysimple gui (using their sample code)

library used in this program (installation is required using pip):
    pyserial (https://pypi.org/project/pyserial/)
    pysimplgui (https://pypi.org/project/PySimpleGUI/)
'''


import serial
import PySimpleGUI as sg
import serial.tools.list_ports
ports = list(serial.tools.list_ports.comports())
for p in ports:
    if "Arduino" in p.description:
        a = p.device      
        break
    elif "USB" in p.description:
        a = p.device      
        break
try:
    arduino = serial.Serial(port=a, baudrate=115200, timeout=.1) 
except:
    sg.theme('DarkRed1')
    layout = [ [sg.Text('Knob cannot be found')],
            [sg.Button('Exit')]]
    window = sg.Window('Knob mode changer', layout)
    event, values = window.read()
    if event == sg.WIN_CLOSED or event == 'Exit': # if user closes window or clicks cancel
        exit()
sg.theme('DarkGreen4') 
layout = [
            [sg.Button('Volume', size=(30,1))],
            [sg.Button('Zoom', size=(30,1))],
            [sg.Button('Scroll', size=(30,1))],
            [sg.Button('Left scroll', size=(30,1))],
            [sg.Button('Arrow', size=(30,1))],
            [sg.Button('Page up down', size=(30,1))],
            [sg.Button('Serial', size=(30,1))],
            [sg.Button('Exit', size=(30,1))]]
window = sg.Window('Knob mode changer', layout, resizable=True, finalize=True,icon='l.ico')
window.bind('<Configure>', "Configure")

while True:
    event, values = window.read()
    if event == 'Exit' or event == sg.WIN_CLOSED: # if user closes window or clicks cancel
        arduino.write(bytes('0', 'utf-8'))
        break
    elif event == 'Volume':
        arduino.write(bytes('0', 'utf-8'))
        
    elif event == 'Zoom':
        arduino.write(bytes('1', 'utf-8'))
        
    elif event == 'Scroll':
        arduino.write(bytes('2', 'utf-8'))
        
    elif event == 'Left scroll':
        arduino.write(bytes('3', 'utf-8'))
        
    elif event == 'Arrow':
        arduino.write(bytes('4', 'utf-8'))

    elif event == 'Page up down':
        arduino.write(bytes('5', 'utf-8'))
    
    elif event == 'Serial':
        arduino.write(bytes('6', 'utf-8'))
        
        
       
    
window.close()
arduino.close()
