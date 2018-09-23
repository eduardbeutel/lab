package journal;

import static JournalEntryConstants.*;
import static untilfour.Untilfour.*;

public class JournalApp
{{

    app("journal");
        .menu()
            .page("entry")
            .endMenu();

    page("entry")

        .search().tableView(JournalEntry)
            .actions(create,delete)
            .filters()
                .searchField(title)
                .dateRangeGroup(created)
                .endFilters()
            .columns("70|15|15")
                .textField(title)
                .dateField(created)
                .dateField(updated)
                .endColumns()
            .endSearch()

        .edit().singleView(JournalEntry)
            .actions(update,delete,clone)
            .verticalLayout()
                .textField(title)
                .horizontalLayout()
                    .dateField(created)
                    .dateField(updated)
                    .endLayout()
                .richTextArea(content)
                .endLayout()
            .endEdit()

        .endPage();

}}
