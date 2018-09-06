from http.server import BaseHTTPRequestHandler, HTTPServer
import json

class RestHandler(BaseHTTPRequestHandler):

    def do_GET(self):
        response = { "test":"server" }
        self.respond(200,json.dumps(response))
        
    def do_POST(self): 
        response = { "test":"server" }
        self.respond(200,json.dumps(response))
        
    def respond(self,code,content):
        self.send_response(code)
        self.send_header('Content-type', 'application/json')
        self.end_headers()    
        if content is not None:
            self.wfile.write(content.encode("utf-8"))        
    
        
if __name__ == "__main__":
    server_address = ('', 8099)
    httpd = HTTPServer(server_address, RestHandler)
    print('Starting server on port ' + str(8099))
    httpd.serve_forever()