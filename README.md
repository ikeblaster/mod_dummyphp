Description
=======
This is a dummy module for Apache which reads and ignores directives `php_value`, `php_flag`, `php_admin_value`, `php_admin_flag` and `PHPINIDir` inside `.htaccess` so no error is generated when `mod_php` is not enabled.

Explanation
========
When you use PHP in Apache through CGI interface (FastCGI/PHP-FPM/fcgid/...) you can often walk into 500 error and message similar to the following one flushed into error log:
> Invalid command 'php_value', perhaps misspelled or defined by a module not included in the server configuration

This is usually caused by directives already mentioned in description, which work only with PHP module loaded directly into Apache process (`mod_php`). 

This module takes care of those directives - **directives are read and ignored**. In other words - having `php_value` inside `.htaccess` will not generate any error nor do the thing it was supposed to (you can use `.user.ini` to solve the latter).
