#### valgrind cmd
```
valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=yes  ./cub3D maps/good/map.cub

```

```

/*
** Counts how many times a specific identifier appears in the file
** Used for floor (F) and ceiling (C) validation
*/
static int	ft_count_identifier(char **file_content, char *identifier)
{
    int	i;
    int	j;
    int	count;

    i = 0;
    count = 0;
    while (file_content[i])
    {
        j = 0;
        while (file_content[i][j] == ' ' || file_content[i][j] == '\t')
            j++;
        if (file_content[i][j] == identifier[0])
        {
            if (file_content[i][j + 1] == ' ' 
                || file_content[i][j + 1] == '\t')
                count++;
        }
        i++;
    }
    return (count);
}

/*
** Verifies that floor (F) and ceiling (C) identifiers appear exactly once
** Returns ERROR if any identifier is missing or duplicated
*/
int	ft_check_floor_ceiling_flag(t_data *data)
{
    int	floor_count;
    int	ceiling_count;

    floor_count = ft_count_identifier(data->file_content, "F");
    ceiling_count = ft_count_identifier(data->file_content, "C");
    if (floor_count != 1)
        return (ft_error("F (floor) identifier must appear exactly once\n"), 
            ERROR);
    if (ceiling_count != 1)
        return (ft_error("C (ceiling) identifier must appear exactly once\n"), 
            ERROR);
    return (SUCCESS);
}

/*
** Finds the line containing the specified identifier (F or C)
** Returns the line or NULL if not found
*/
static char	*ft_find_color_line(char **file_content, char identifier)
{
    int	i;
    int	j;

    i = 0;
    while (file_content[i])
    {
        j = 0;
        while (file_content[i][j] == ' ' || file_content[i][j] == '\t')
            j++;
        if (file_content[i][j] == identifier)
        {
            if (file_content[i][j + 1] == ' ' 
                || file_content[i][j + 1] == '\t')
                return (file_content[i]);
        }
        i++;
    }
    return (NULL);
}

/*
** Extracts the RGB color string from a line
** Skips identifier and whitespace, returns the RGB part
*/
static char	*ft_extract_color_string(char *line)
{
    int		i;
    int		j;
    char	*color_str;

    i = 0;
    while (line[i] == ' ' || line[i] == '\t')
        i++;
    i++;
    while (line[i] == ' ' || line[i] == '\t')
        i++;
    j = i;
    while (line[j] && line[j] != '\n')
        j++;
    color_str = ft_substr(line, i, j - i);
    return (color_str);
}

/*
** Frees a split array of strings
*/
static void	ft_free_split(char **split)
{
    int	i;

    i = 0;
    while (split[i])
    {
        free(split[i]);
        i++;
    }
    free(split);
}

/*
** Counts elements in a split array
*/
static int	ft_count_split(char **split)
{
    int	count;

    count = 0;
    while (split[count])
        count++;
    return (count);
}

/*
** Removes leading and trailing whitespace from a string
*/
static char	*ft_trim_whitespace(char *str)
{
    int		i;
    int		start;
    int		end;
    char	*trimmed;

    i = 0;
    while (str[i] == ' ' || str[i] == '\t')
        i++;
    start = i;
    end = ft_strlen(str) - 1;
    while (end > start && (str[end] == ' ' || str[end] == '\t' 
        || str[end] == '\n'))
        end--;
    trimmed = ft_substr(str, start, end - start + 1);
    return (trimmed);
}

/*
** Parses RGB values from a color string and stores them in the array
** Format: "R,G,B" where each value is 0-255
*/
static int	ft_parse_rgb(char *color_str, int *rgb_array)
{
    char	**split;
    char	*trimmed;
    int		i;

    split = ft_split(color_str, ',');
    if (!split || ft_count_split(split) != 3)
    {
        if (split)
            ft_free_split(split);
        return (ft_error("RGB format must be R,G,B\n"), ERROR);
    }
    i = 0;
    while (i < 3)
    {
        trimmed = ft_trim_whitespace(split[i]);
        rgb_array[i] = ft_atoi(trimmed);
        free(trimmed);
        i++;
    }
    ft_free_split(split);
    return (SUCCESS);
}

/*
** Stores floor and ceiling color values in the texture structure
** Parses the RGB strings and converts them to integer arrays
*/
int	ft_store_floor_ceiling_color(t_data *data)
{
    char	*line;
    char	*color_str;

    line = ft_find_color_line(data->file_content, 'F');
    if (!line)
        return (ft_error("floor color line not found\n"), ERROR);
    color_str = ft_extract_color_string(line);
    data->texture->floor = color_str;
    if (ft_parse_rgb(color_str, data->texture->floor_tab) == ERROR)
        return (ERROR);
    line = ft_find_color_line(data->file_content, 'C');
    if (!line)
        return (ft_error("ceiling color line not found\n"), ERROR);
    color_str = ft_extract_color_string(line);
    data->texture->ceiling = color_str;
    if (ft_parse_rgb(color_str, data->texture->ceiling_tab) == ERROR)
        return (ERROR);
    return (SUCCESS);
}

/*
** Validates that all RGB values are in the valid range (0-255)
** Checks both floor and ceiling color arrays
*/
int	ft_is_rgb_valid(t_data *data)
{
    int	i;

    i = 0;
    while (i < 3)
    {
        if (data->texture->floor_tab[i] < 0 
            || data->texture->floor_tab[i] > 255)
        {
            return (ft_error("floor RGB values must be between 0 and 255\n"), 
                ERROR);
        }
        if (data->texture->ceiling_tab[i] < 0 
            || data->texture->ceiling_tab[i] > 255)
        {
            return (ft_error("ceiling RGB values must be between 0 and 255\n"), 
                ERROR);
        }
        i++;
    }
    return (SUCCESS);
}

```
