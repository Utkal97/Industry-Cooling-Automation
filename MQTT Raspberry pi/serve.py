from flask import Flask, url_for, render_template, request, redirect, url_for
from flask_restful import Resource, Api, reqparse

import json
import os
import logging


app = Flask(__name__)
api = Api(app)

@app.route('/')
def hello_world():
        return 'Hello from Flask!'

@app.route('/data', methods=['GET', 'POST'])
def detectfaces():
        if request.method == 'POST':
                data = request.json
                response = json.dumps({'faces' : "Recieved"})
                return response
        else:
                return 'GET not supported'

if __name__ == '__main__':
        # Create MTCNN detector here
        app.run(host='0.0.0.0', port=80, debug=True)