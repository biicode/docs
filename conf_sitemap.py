import sys, os, shutil, getopt

print "argvs: %s" % str(sys.argv)
opts, args = getopt.getopt( sys.argv[1:], 'ab:d:c:CD:A:NEqQP:w')
print 'opts: ', opts
print 'args: ', args

outdir = args[1]
project_root = os.path.abspath('..')
doc_project_root = os.path.abspath('.')

def generate_sitemap(app, exception):

    if exception:
        print 'SITEMAP generation was skipped - there were errors during the build process'
        return
    try:
    	print os.path.curdir
        import sitemap_gen

        working_dir = os.path.join( doc_project_root, outdir )
        config = \
        """<?xml version="1.0" encoding="UTF-8"?>
        <site base_url="http://docs.biicode.com/" store_into="%(path)s/sitemap.xml.gz" verbose="1">
            <directory path="%(path)s" url="http://docs.biicode.com/" default_file="index.html" />
            <filter  action="drop"  type="regexp"    pattern="/\.[^/]*" />
            <filter  action="drop"  type="regexp"    pattern="/_[^/]*" />
        </site>
        """ % dict( path=os.path.join( doc_project_root, working_dir ) )

        f_config_path = os.path.join( working_dir, 'sitemap_config.xml' )
        f_config = file( f_config_path, 'w+' )
        f_config.write( config )
        f_config.close()

        sitemap = sitemap_gen.CreateSitemapFromFile(f_config_path, True)
        if not sitemap:
            print 'ERROR(SITEMAP): configuration file errors'
        else:
            sitemap.Generate()
            print 'ERRORS(SITEMAP): %d' % sitemap_gen.output.num_errors
            print 'WARNINGS(SITEMAP): %d' % sitemap_gen.output.num_warns
    except Exception, error:
        print "ERROR(SITEMAP): sitemap file was not generated - ", str(error)
