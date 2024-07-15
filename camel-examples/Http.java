// camel-k: language=java

import org.apache.camel.builder.RouteBuilder;

public class Http extends RouteBuilder { @Override public void configure() throws Exception {

    from("jetty:http://localhost:33897/test")
        .to("stream:out")
        ;

    from("stream:in?promptMessage=Enter something: ")
        .to("http:localhost:33897/test")
        ;

}}
