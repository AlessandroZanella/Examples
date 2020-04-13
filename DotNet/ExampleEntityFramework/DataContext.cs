
using Microsoft.EntityFrameworkCore;

public class DataContext : DbContext 
{
    protected override void OnConfiguring(DbContextOptionsBuilder optionsBuilder)
    {
        optionsBuilder.UseSqlServer(@"Server=localhost\SQLEXPRESS;Database=ExampleEntityFrameworkDB;Trusted_Connection=True;MultipleActiveResultSets=true");
    }
    public DbSet<Book> Books { get; set; }

    public DbSet<Author> Authors { get; set; }
}