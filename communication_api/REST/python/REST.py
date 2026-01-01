import requests

class RESTClient:
    def __init__(self, base_url):
        self.base_url = base_url

    def get(self, endpoint, params=None, headers=None):
        url = f"{self.base_url}/{endpoint}"
        response = requests.get(url, params=params, headers=headers)
        return self._handle_response(response)

    def post(self, endpoint, data=None, json=None, headers=None):
        url = f"{self.base_url}/{endpoint}"
        response = requests.post(url, data=data, json=json, headers=headers)
        return self._handle_response(response)

    def put(self, endpoint, data=None, json=None, headers=None):
        url = f"{self.base_url}/{endpoint}"
        response = requests.put(url, data=data, json=json, headers=headers)
        return self._handle_response(response)

    def delete(self, endpoint, headers=None):
        url = f"{self.base_url}/{endpoint}"
        response = requests.delete(url, headers=headers)
        return self._handle_response(response)

    def _handle_response(self, response):
        if response.status_code >= 200 and response.status_code < 300:
            try:
                return response.json()
            except ValueError:
                return response.text
        else:
            response.raise_for_status()

def main():
    MY_API_KEY = open("../key.txt", "r").read().strip()
    CITY_NAME = input("Enter City Name: ")
    client = RESTClient(f"https://api.openweathermap.org/data/2.5/weather?q={CITY_NAME}&appid={MY_API_KEY}&units=imperial")
    response = client.get("")
    try:
        print(f"Temperature in {CITY_NAME}: {response['main']['temp']}°F")
    except KeyError:
        print(f"Error: {response}")

if __name__ == "__main__":
    main()