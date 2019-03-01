import motor.motor_asyncio
from aiohttp import web
import country

app = web.Application()

async def index(request):
    return web.FileResponse('./index.html')
    
app.add_routes([web.get('/', index),
                web.get('/country', country.get_all),
                web.get('/country/{id}', country.get_by_id)
                ])
                
web.run_app(app,port=8090)
    
    
