// camel-k: language=java

import org.apache.camel.builder.RouteBuilder;

public class TriggeredPoll extends RouteBuilder { @Override public void configure() throws Exception {

    from("stream:in?promptMessage=Hit enter to trigger poll:")
        .pollEnrich("file:./queue-to-poll")
        .to("stream:out")
        ;


}}
