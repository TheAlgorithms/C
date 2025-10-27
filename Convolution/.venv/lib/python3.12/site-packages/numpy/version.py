
"""
Module to expose more detailed version info for the installed `numpy`
"""
version = "2.3.4"
__version__ = version
full_version = version

git_revision = "1458b9e79d1a5755eae9adcb346758f449b6b430"
release = 'dev' not in version and '+' not in version
short_version = version.split("+")[0]
