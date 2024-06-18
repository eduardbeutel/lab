# REST CRUD Pattern

    Create:
        POST /entity
    Retrieve:
        by id: GET /entity/id
        by simple query: GET /entity?filter1=value1&filter2=value2&sortByAsc=filter1&page=1&pageSize=10&view=summary
        by complex query: POST /entity/retrieve
    Update:
        by id: PUT /entity/id
        by simple query: PUT /entity?filter1=value1&filter2=value2&sortByAsc=filter1&page=1&pageSize=10&view=summary
        by complex query: POST /entity/update
    Delete:
        by id: DELETE /entity/id
        by simple query: DELETE /entity?filter1=value1&filter2=value2
        by complex query: POST /entity/delete
        
