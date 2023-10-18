#include "shell.h"

/**
 * get_user_assist - get text from user with helper func.
 * @_line_ptr: user input message
 * @n: user input integers
 * Return: return an integer.
 */
int get_user_assist(char **_line_ptr, size_t *n)
{
	if (*_line_ptr == NULL || *n == 0)
	{
		*n = 128;
		*_line_ptr = malloc(*n);
		if (*_line_ptr == NULL)
			return (-1);
	}
	return (0);
}

/**
 * get_userdata - get user input from stream.
 * @_line_ptr: user input message
 * @n: user input integer
 * @stream: check the stream and compare to see much in File.
 * Return: return ssize_t
 */
ssize_t get_userdata(char **_line_ptr, size_t *n, FILE *stream)
{
	ssize_t _bytestobeRead = 0;
	size_t _posi = 0, _nSize;
	static char buffer[READ_BUF_SIZE];
	static size_t _bufSize, _bufPosi;
	char *_newBuff;
	bool keep_running = true;

	if (_line_ptr == NULL || n == NULL || stream == NULL
		|| get_user_assist(_line_ptr, n) == -1)
		return (-1);
	while (keep_running)
	{
		if (_bufPosi >= _bufSize)
		{
			_bytestobeRead = read(stream->_fileno, buffer, READ_BUF_SIZE);
			if (_bytestobeRead <= 0 && _posi == 0)
				return (-1);
			else if (_bytestobeRead <= 0)
				break;
			_bufSize = _bytestobeRead;
			_bufPosi = 0;
		}
		if (_posi >= *n - 1)
		{
			_nSize = *n * 2;
			_newBuff = realloc(*_line_ptr, _nSize);
			if (_newBuff == NULL)
				return (-1);
			*_line_ptr = _newBuff;
			*n = _nSize;
		}
		(*_line_ptr)[_posi++] = buffer[_bufPosi++];
		if ((*_line_ptr)[_posi - 1] == '\n')
			break;
	}
	(*_line_ptr)[_posi] = '\0';
	return (_posi);
}

