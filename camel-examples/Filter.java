// camel-k: language=java

import org.apache.camel.builder.RouteBuilder;

public class Filter extends RouteBuilder { @Override public void configure() throws Exception {

    from("file:./?fileName=cds.xml&noop=true")
            .filter().xpath("/CATALOG")
            .to("stream:out")
            ;

}}
