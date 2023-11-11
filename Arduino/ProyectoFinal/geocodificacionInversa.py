# ************************** ARDUINO DATA **************************

import serial, time, requests

# Crea una conexión serial
ser = serial.Serial('COM6', 9600)  # Reemplaza 'COM6' con el puerto correcto
addressSend = True

# Lee algunos datos
for i in range(5):
    arduinoData = ser.readline().decode('ascii')
    latitud, longitud = arduinoData.split(',')
    print(f'Latitud: {latitud}, Longitud: {longitud}')

# *************************** API MAPS *********************


def get_address_by_location(latitude, longitude, api_key='AIzaSyBBda4RyLmJz0B3d0T8vQ-5ZWIvLlBcCJA'):
    """Get address by location coordinates."""
    url = f'https://maps.googleapis.com/maps/api/geocode/json?latlng={latitude},{longitude}&key={api_key}'
    response = requests.get(url)
    data = response.json()
    if len(data['results']) > 0:
        return data['results'][0]['formatted_address']
    return None

# Define tus coordenadas
latitude = 'latitud'
longitude = 'longitud'

# Obtén la dirección
address = get_address_by_location(latitude, longitude)
print(address)

# ************************** ARDUINO SEND ************************

ser.write(addressSend.encode())
time.sleep(2)
ser.write(address.encode())



