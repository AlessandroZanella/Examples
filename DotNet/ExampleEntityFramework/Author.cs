
using System.Collections.Generic;

public class Author 
{
    public Author()
    {
        Books = new HashSet<AuthorBook>();
    }

    public int AuthorID { get; set; }

    public string Name { get; set; }

    public string Surname { get; set; }

    public virtual ICollection<AuthorBook> Books { get; set; }
}