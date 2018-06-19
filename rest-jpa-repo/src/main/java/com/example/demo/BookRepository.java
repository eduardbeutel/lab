package com.example.demo;

import org.springframework.data.repository.PagingAndSortingRepository;
import org.springframework.data.rest.core.annotation.RepositoryRestResource;

/**
 * Creation Date: 30.05.2018 10:41<br/>
 * &copy; Information Design One AG
 * @author Eduard Beutel
 */
@RepositoryRestResource(collectionResourceRel = "book", path = "book")
public interface BookRepository extends PagingAndSortingRepository<Book, Long>
{
}
