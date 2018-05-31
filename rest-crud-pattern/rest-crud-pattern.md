# REST CRUD Pattern

    Create:
        POST /entity
    Retrieve:
        by id: GET /entity/id
        by simple query: GET /entity?filter1=value1&filter2=value2&sortByAsc=filter1&page=1&pageSize=10&view=summary
        by complex query: POST /entity/query
    Update:
        PUT /entity/id
    Delete:
        by id: DELETE /entity/id
        by simple query: DELETE /entity?filter1=value1&filter2=value2
        
## Simple Query


## Complex Query
