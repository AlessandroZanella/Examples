
using System.Collections.Generic;

public class Book 
{
    public Book()
    {
        Authors = new HashSet<AuthorBook>();
    }

    public int BookID { get; set; }

    public string Title { get; set; }

    public string Description { get; set; }
    
    public virtual ICollection<AuthorBook> Authors { get; set; }
}