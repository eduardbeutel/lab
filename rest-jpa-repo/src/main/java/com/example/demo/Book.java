package com.example.demo;

import java.util.Date;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.validation.constraints.NotBlank;
import javax.validation.constraints.NotNull;
import javax.validation.constraints.Positive;

import lombok.Data;
import org.hibernate.validator.constraints.Length;
import org.hibernate.validator.constraints.ScriptAssert;

/**
 * Creation Date: 30.05.2018 10:30<br/>
 * &copy; Information Design One AG
 * @author Eduard Beutel
 */
@Entity
@Data
public class Book
{

    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long id;

    @Length(min=3,max=50) // hibernate validator constraint
    private String name;

    @NotNull
    @Positive // javax.validation constraint
    private Double price;

    private Date validFrom;

    private Date validTo;

}
