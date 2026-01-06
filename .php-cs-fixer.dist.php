<?php

$finder = PhpCsFixer\Finder::create()
    ->in(__DIR__)
    ->exclude(['vendor', 'storage', 'bootstrap/cache'])
    ->name('*.php')
    ->ignoreDotFiles(true)
    ->ignoreVCS(true);

$config = new PhpCsFixer\Config();

// Define the cache path in your user home directory
$cacheDir = getenv('HOME').'/.cache/php-cs-fixer';

// Ensure the directory exists so the tool doesn't crash
if (!is_dir($cacheDir)) {
    mkdir($cacheDir, 0755, true);
}

return $config->setRules([
    '@Symfony' => true,
    'array_syntax' => ['syntax' => 'short'],
    'ordered_imports' => ['sort_algorithm' => 'alpha'],
    'no_unused_imports' => true,
    'trailing_comma_in_multiline' => true,
    'phpdoc_scalar' => true,
    'unary_operator_spaces' => true,
    'binary_operator_spaces' => true,
    'blank_line_before_statement' => [
        'statements' => ['break', 'continue', 'declare', 'return', 'throw', 'try'],
    ],
])
    ->setFinder($finder)
    ->setCacheFile($cacheDir.'/.php-cs-fixer.cache')
    ->setUsingCache(true);
