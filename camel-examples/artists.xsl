<?xml version="1.0"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

<xsl:template match="/">
    <ARTISTS>
        <xsl:for-each select="CATALOG/CD">
        <ARTIST><xsl:value-of select="ARTIST"/></ARTIST>
        </xsl:for-each>   
    </ARTISTS>
</xsl:template>

</xsl:stylesheet> 