import requests
import json

# Define the URL
url = 'https://animated-meme-54xr569ppj434r9w-5005.app.github.dev/webhooks/rest/webhook'

# Define the header
headers = {'Content-Type': 'application/json'}

# Define the data
data = {
    'message': 'Hi Rasa!!!'
}

# Convert the data to JSON format
data_json = json.dumps(data)

# Send the POST request
response = requests.post(url, headers=headers, data=data_json)

# Print the response
print(response.text)