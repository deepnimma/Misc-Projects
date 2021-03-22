from PyPDF2 import PdfFileMerger

volumes = 0

volumes = int(input('Enter Number of Volumes: '))

for current_volume in range(0, volumes):
    chapters = []
    chapter_file_name = []

    beginning_chapter = 1
    ending_chapter = int(input('Enter Ending Chapter for Volume %d: ' % (current_volume + 1)))

    for i in range(beginning_chapter, ending_chapter + 1):
        chapters.append(i)
        chapter_file_name.append(str(i) + '.pdf')
        print('Chapter %d Added to List...' % (i))

    merger = PdfFileMerger()

    print('Merger Created')

    for pdf in chapter_file_name:
        merger.append(pdf)
        print('%s added...' % (pdf))

    final_file_name = 'Volume ' + str(current_volume + 1) + '.pdf'

    merger.write(final_file_name)
    merger.close()

    print(final_file_name + " Completed! \n")

    # print(final_file_name)

    # print(chapters, chapter_file_name)


# pdfs = ['1.pdf', '2.pdf', '3.pdf', '4.pdf', '5.pdf', '6.pdf', '7.pdf']

# merger = PdfFileMerger()

# for pdf in pdfs:
#     merger.append(pdf)

# merger.write('Volume 1.pdf')
# merger.close()