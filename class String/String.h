class String
{
public:
    String leftpart(int band);
    String rightpart(int band);
    String middle(int start, int band);
    String concatenation(String input);

    String();
    String(const char *input);

    int len();
    char *to_char();

private:
    int length = 0;
    char *array;

    void eol();

    int get_len(const char *input);
};