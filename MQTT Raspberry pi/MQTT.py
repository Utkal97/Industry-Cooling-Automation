import requests
import json
import sys

def main(argv):
    image1 = "Test"
    payload = {'image': image1}

    # json.dumps(payload)
    r = requests.post('http://52.66.200.36:8000/data', json=payload)
    print r.json()


if __name__ == "__main__":
    main(sys.argv)