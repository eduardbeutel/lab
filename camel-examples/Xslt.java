// camel-k: language=java

import org.apache.camel.builder.RouteBuilder;

public class Xslt extends RouteBuilder { @Override public void configure() throws Exception {

    from("file:./?fileName=cds.xml&noop=true")
        .routeId("r1")
        .to("xslt:file:artists.xsl")
        .to("stream:out")
        ;

}}
