from http.server import BaseHTTPRequestHandler, HTTPServer
import json
import pathlib
import logging
import posixpath

class FileBasedRestHandler(BaseHTTPRequestHandler):

    def do_GET(self):
        # root
        if self.path == '/':
            return self.respond_with_file('index.html','text/html')
        # html
        elif self.path.endswith('.html'):
            return self.respond_with_html()
        # js
        elif self.path.endswith('.js'):
            return self.respond_with_js()
        # json
        else: 
            return self.respond_with_json('get')
        
    def do_POST(self):
        return self.respond_with_json('post')

    def do_UPDATE(self):
        return self.respond_with_json('update')    
    
    def do_DELETE(self):
        return self.respond_with_json('delete')
                
    def respond_with_html(self):
        filepath = "." + self.path
        return self.respond_with_file(filepath,'text/html')

    def respond_with_js(self):
        filepath = "." + self.path
        return self.respond_with_file(filepath,'application/javascript')
        
    def respond_with_json(self,filename_prefix):
        filename = filename_prefix + self.path.replace('/','-').replace('?','&') + '.json'
        return self.respond_with_file(filename,'application/json')

    def respond_with_file(self,filepath,content_type):
        try:
            response = pathlib.Path(filepath).read_text()
            self.respond(200,content_type,response)
        except FileNotFoundError:
            return self.respond_with_not_found()
            
    def respond_with_not_found(self):
        self.respond(404,"application/json",json.dumps({"error":"404"}))
    
    def respond(self,code,content_type,content):
        self.send_response(code)
        self.send_header('Content-type', content_type)
        self.send_header('Access-Control-Allow-Origin','*')
        self.end_headers()    
        if content is not None:
            self.wfile.write(content.encode("utf-8"))        
    
        
if __name__ == "__main__":
    port = 8099
    server_address = ('', port)
    httpd = HTTPServer(server_address, FileBasedRestHandler)
    print('Starting server on port ' + str(port))
    httpd.serve_forever()