from aiohttp import web
from bson.json_util import dumps as bson_to_json
import motor.motor_asyncio as motor
import json

async def get_by_id(request):
    id = request.match_info.get('id')
    query = {'alpha-2':id.upper()}
    
    client = motor.AsyncIOMotorClient()
    countries = client.db.countries
    cursor = countries.find(query)
    result = await cursor.to_list(length=1)
    doc = bson_to_json(result)
    return web.Response(body=doc,content_type='application/json')
    
async def get_all(request):
    client = motor.AsyncIOMotorClient()
    countries = client.db.countries
    cursor = countries.find()
    result = await cursor.to_list(None)
    docs = bson_to_json(result)
    return web.Response(body=docs,content_type='application/json')
        