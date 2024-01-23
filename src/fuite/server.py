from http.server import BaseHTTPRequestHandler, HTTPServer
from urllib.parse import urlparse

hostName = "0.0.0.0"
serverPort = 8080

reserve = []

class MyServer(BaseHTTPRequestHandler):
    def do_GET(self):
        self.send_response(200)
        self.send_header("Content-type", "text/html")
        self.end_headers()
        self.wfile.write(bytes("OK!", "utf-8"))
        query = urlparse(self.path).query
        query_components = dict(qc.split("=") for qc in query.split("&"))
        
        for i in range(0,int(query_components["m"])):
            for k in range(0,131072):
                reserve.append(42)
        
        
if __name__ == "__main__":        
    webServer = HTTPServer((hostName, serverPort), MyServer)
    print("Server started http://%s:%s" % (hostName, serverPort))

    try:
        webServer.serve_forever()
    except KeyboardInterrupt:
        pass

    webServer.server_close()
    print("Server stopped.")