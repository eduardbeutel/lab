// camel-k: language=java

import org.apache.camel.builder.RouteBuilder;

public class Cli extends RouteBuilder { @Override public void configure() throws Exception {

    from("stream:in?promptMessage=Enter something:")
        .to("stream:out")
        ;

}}
