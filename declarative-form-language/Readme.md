# untilfour

A declarative language for data entry applications based on the concept of forms.

Journal app example:

    <app id="journal" xmlns="https://github.com/eduardbeutel/untilfour/v1">

        <form id="entry">
            <field id="title" />
            <layout type="horizontal">
                <field id="#created" />
                <field id="#updated" />
            </layout>
            <field id="body" type="richText" />
        </form>

    </app>











