
    
#!/usr/bin/env python3

# NOTE: this example requires PyAudio because it uses the Microphone class

import speech_recognition as sr
import json

# obtain audio from the microphone

json_data = r'{ "type": "service_account", "project_id": "applied-arcanum-234709", "private_key_id": "6a8f17d1aa649774992b657b7287f14447e0ba75", "private_key": "-----BEGIN PRIVATE KEY-----\nMIIEvAIBADANBgkqhkiG9w0BAQEFAASCBKYwggSiAgEAAoIBAQC9ZYA3kiKsQ7qL\nAyRnodZwGQMGiqvNYprj4Um2XSHPjfPkCgDioWWMZJZPzzvbzX2rYU6zcpSIDljJ\ngtNYjC5AYFCr5ZROWOPobpi76xYoUVKRQHiG2AeXLwcWE7lA3wS7yQzEbURFVTcl\n/AdcDAziPLtQ51LlUm/jPACZ5hFqSCma30iZsSU0ukYRa9bkvz1jvYnSI05S7V9o\neKSK+N+NMFoQw3Xr4MEx4Q3C3LpN8FZ9vDT4XMAGKc2KDJSjn++mIYdZKFAI5jg+\nlaBIK0N/mXS9O6/J1PJuY6LvS6yUBj74qcBivGOQDoOpmyhW6wsuG0elyKZ7/LXN\n0utoh5cnAgMBAAECggEAChcTvyIqdboAALLwqBK/rWYvupP9tin4LYbNmgkZKYkb\nAr2jsW8+zT14opTcUAgBF3XOLxI+Jod5JHczUkbZmfVnptjKz2e98J6fxXcvTYOT\nnghsw2ZT9TJ8sqjnWDTpeCWsZ/SYTAdPslbcf4Nm1lC8/ADu8iezrUv/jjNrHxnU\nh6n0V9c2eo5r9Fcx1euBLQv9azyRaCFVDrDsDrsH4beD0NXzDxxFCiNjqJ5jRv1M\nw2oc1lE0wes4gSdarvAp1ZYK8VxrbXVFfZt/OTzY98q6MSTDpDhK9F783rtRYPlq\nXrF7x3n8NqK83xhuXzq3K/x7py/RyxDVbF5JQPXFtQKBgQDyWfztX6CahlAjJk5i\nqJOtBierCKDQK+sXtO2Yg27MBDo+IUkExRnopKsnWCgBIaG7C28J4D7azve9PrSX\nc07Mrs7a1SZO+tbVk+MHvk1jB+7QvdpcbfVubE68EVdxQ/Rjx9J1sUyzj/SvjsHx\nJVT2BeRp7lKvLwSilmPf6zCsbQKBgQDIEA25pHxfleVjWSiowtX0aH+CiGbXHN+D\nIFD1ZhSI3fKpIDeeISTCTjJJGy+d6Bzp67rf6KNoRIFBgHmeXQRsRMumuvjRXl5b\nFkKlrrSLn/qPxT1qBCZB7xiDduM/8n2c3CqDViHhTMLxVeLldzwWpTcTaWmmShmo\nJzbopOTtYwKBgEopfXvKUqRWy7kl5MDOI3rEMmllV4i8l9GGXVrZhZNLC+OtXeHm\nyvnlQjblBEDsYMiTRCR6ieF9ilRQFwVtlMSQDd7rcTCkFBABlGzvMFFIwS0BnAvC\n3mMvI5zrlZ2klOnf4SiA3B7qw47hmbnImco7nV1JP+Y59iom6WNBXoC1AoGAXN5G\n4MQgD+bvIp0CqMQ4uUnA1wEma/i1MJNRwXhvU9FjkWqpJrhP7fqKkTETe4OB2Hxa\ntRGyuPYD4joXOpIHOZL9zhnA4r+hoTrGGU7t9FqA3zg59/qRH84zXONVPhv8f1Ic\nUfcrpwARBiJOPyKIPCLZXCN0rYJ8QnhhnsDcm+0CgYAvVqFrVZUK0XRn5XmAZiBA\n9lRj+ZSnZOkpkqm2bPnbOjTw7xETYTce055XV45yP2XzvlQYd+2zHZ5J3EitZexm\nlbygmKwLnNZXoSNmeaJHBi8ZBnG5jPXxJUdSH2dX6kRLwx9aX2lZVroVN+08XKYB\n6qF4dbEpRBVaoC3rnSHcFw==\n-----END PRIVATE KEY-----\n", "client_email": "anurag-kumar@applied-arcanum-234709.iam.gserviceaccount.com", "client_id": "110733704330574751888", "auth_uri": "https://accounts.google.com/o/oauth2/auth", "token_uri": "https://oauth2.googleapis.com/token", "auth_provider_x509_cert_url": "https://www.googleapis.com/oauth2/v1/certs", "client_x509_cert_url": "https://www.googleapis.com/robot/v1/metadata/x509/anurag-kumar%40applied-arcanum-234709.iam.gserviceaccount.com" }'

r = sr.Recognizer()
with sr.Microphone() as source:
    print("Say something!")
    audio = r.listen(source)

print("r")

try:
    print("Google Cloud Speech thinks you said " + r.recognize_google_cloud(audio, credentials_json=json_data))
except sr.UnknownValueError:
    print("Google Cloud Speech could not understand audio")
except sr.RequestError as e:
    print("Could not request results from Google Cloud Speech service; {0}".format(e))